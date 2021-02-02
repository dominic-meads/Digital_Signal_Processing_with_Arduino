/*
implements a right shift of an array (takes all indecies in array, shifts them right and leaves clear spot for new data)
*/

// function declarations /////////////////////////////////////////////////////////////////////////
void right_shift_arr(int * array, int leng);  
void print_arr(int * array, int length);


// main /////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);  // for testing using printing functions
  
  int my_array [10] = {1,2,3,4,5,6,7,8,9,10}; 
  int my_array_length = 10;
  
  Serial.print("Original array:\n");
  print_arr(my_array,my_array_length);
  
  Serial.print("array shifted right 1 place:\n");
  right_shift_arr(my_array,my_array_length);
  print_arr(my_array,my_array_length);  
}

void loop() {
  
    
}


// function definitions /////////////////////////////////////////////////////////////////////////

void right_shift_arr(int * array, int length)  
{
	for(int i = length - 1; i > 0; i--)
	{
		array[i]=array[i-1];
	}
	array[0]=0;
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
