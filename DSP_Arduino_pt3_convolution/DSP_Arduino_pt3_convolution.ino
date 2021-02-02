/*
  This function performs a convolution based on two arrays
*/

// function declarations /////////////////////////////////////////////////////
float convolve(int * array, float * kernel, int length);
void print_arr(int * array, int length);
void right_shift_arr(int * array, int length);


// main //////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  int x_shifted [5] = {};  // the array that we shift sequence x into (from example)
  int x_length = 5;                  // length of array
  float h [5] = {-2,3,1,6,4};        // what will be known as the filter kernel
  int h_length = 5;
  float result [9] = {};             // result array (lengthx+lengthh-1)
  
  for(int i = 0; i < 9; i++)         // this loop wil simulate the sampling process
  {
    right_shift_arr(x_shifted,x_length);  // first shift to make room for a new sample
    
    // this next section simulates an adc conversion taking place
    Serial.print("enter new sample: ");
    while (Serial.available() == 0){}
    x_shifted[0] = Serial.parseInt();         // place new "sample" into array
    Serial.print("\n");
    //
    
    result[i] = convolve(x_shifted,h,h_length);  // both lengths are the same 
  }
  
  Serial.print("[1,2,4,-1,3] convolved with [-2,3,1,6,4] is:\n");  // h is type float so cannot be printed using print_arr function
  for(int i = 0; i < 9; i++)
  {
    Serial.print(result[i]);
    Serial.print(" ");
  }
  
}

void loop() {
    
}


// function definitions //////////////////////////////////////////////////////
float convolve(int * array, float * kernel, int length)  // performs a convolution
{
	float result = 0;  // output
	for(int i = 0; i < length; i++)
	{
		result += array[i] * kernel[i];  // MAC
	}
	
	return result;
}
	
void print_arr(int * array, int length)
{
  for(int i = 0; i < length; i++)
  {
    Serial.print(array[i]);
    Serial.print(' ');       // just print a space
  }
  Serial.print('\n');
} 

void right_shift_arr(int * array, int length)  
{
	for(int i = length - 1; i > 0; i--)
	{
		array[i]=array[i-1];
	}
	array[0]=0;
}
