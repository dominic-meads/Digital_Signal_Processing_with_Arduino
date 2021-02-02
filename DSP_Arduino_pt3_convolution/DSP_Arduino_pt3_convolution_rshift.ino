/*
implements a right shift of an array (takes all indecies in array, shifts them right and leaves clear spot for new data)
*/

// function declarations /////////////////////////////////////////////////////////////////////////
void right_shift_arr(int * array, int size);  
void print_arr(int * array, int size);


// main /////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);  // for testing using printing functions
  
  int my_array [10] = {1,2,3,4,5,6,7,8,9,10}; 
  int my_array_size = 10;
  
  Serial.print("Original array:\n");
  print_arr(my_array,my_array_size);
  
  Serial.print("array shifted right 1 place:\n");
  right_shift_arr(my_array,my_array_size);
  print_arr(my_array,my_array_size);  
}

void loop() {
  
    
}


// function definitions /////////////////////////////////////////////////////////////////////////

void right_shift_arr(int * array, int size)  
{
	for(int i = size - 1; i > 0; i--)
	{
		array[i]=array[i-1];
	}
	array[0]=0;
}

	
void print_arr(int * array, int size)
{
  for(int i = 0; i < size; i++)
  {
    Serial.print(array[i]);
    Serial.print(' ');       // just print a space
  }
  Serial.print('\n');
}  
