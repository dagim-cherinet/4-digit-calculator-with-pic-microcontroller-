# 4-digit Calculator with PIC16f877a Microcontroller

## This project is focused on design and implementation of a microcontroller based calculator which will perform arithmetic operation using a 4x4 keypad and a 16x2 Liquid Crystal Display (LCD). The calculator is limited to four digit input from 0000 up to 9999. This allows the program for the arithmetic operations to be simple, while the same principles can be extended to any-digit calculations.

## Circuit diagram
![circuit diagram](https://user-images.githubusercontent.com/80765887/183245079-c0a67c32-d47d-4c6f-9cf1-1ab36d2992be.png)

## The calculator operates as follows:
- In order to perform a calculation, enter 4 digit number key, followed by an operation key, then another 4 digit number and then equals to sign ‘=’.
- The clear key erases the current display, and a new calculation can be entered. If an invalid key sequence is entered, the program should be restarted.

## Features of this calculator
- It can accept any four digit number from 0000 to 9999. 
- Can implement 4 operations i-e addition, subtraction, multiplication and division.
- 'ON/C' button reset the calculator at any time.
- Error messages are displayed if wrong input is pressed. For example, if calculator is expecting a number, but a function key is pressed then 'Wrong Input' message is displayed. Similarly, 'operator Expected’ message is displayed if wrong key is pressed instead of a function key.

## Algorithm
- 1.	Initialize LCD.
- 2.	Wait for key pressed from the Keypad.
- 3.	Print whenever the user enters a key.
- 4.	If it is number, then store it in array of 1st 4 digit number.
- 5.	If the key is not a number print error message
- 6.	Wait for operator and store the operator. If the pressed key is not operator print error message.
- 7.	Wait for the second  4 digit number
- 8.	Store the number only if all digits are number
- 9.	Now convert 1st and 2nd no. string (array of char) to long integer.
- 10.	Do operation when “=” key is pressed.
- 11.	And print calculated result on LCD.

## Functions which are part of firmware code
#### void main()
Main Function the heart of the code. Main function executes first. All other functions executes after it.
#### void lcdcmd  (unsigned char)
This function sends commands and controls lcds registers to execute the command properly.  
#### void lcddata (unsigned char)
This function sends data to lcd display and controls lcds registers to display data on 16×2 lcd.
#### void disp_num(float num)
This function displays calculated value or output result on 16×2 lcd display efficiently. 
#### int get_num  (char ch)
This function converts character value to integer. To display integer value on 16×2 lcd it must first be converted in to character format. On 16×2 lcd we can display a character 8-bit value.
#### void lcdinit ()
This function initializes the character lcd display. 16×2 lcd, font-size 7×5, cursor blinking etc.
#### char scan_key(void)
This functions checks which keypad key is pressed by the user.

## Board layout
![board](https://user-images.githubusercontent.com/80765887/183245264-8ef7cca0-0d3e-4227-bd3c-67e115d8744f.png)

## Result

Managed to successfully design and simulate 4-digit Calculator using PIC16F877A microcontroller on Proteus which can perform the four basic arithmetic operations on numbers from 0000 up to 9999.
