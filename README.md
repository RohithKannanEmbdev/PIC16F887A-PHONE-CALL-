# PIC16F887A-PHONE-CALL
CODE AND HARWARE DISCRIPTION 
Key Components:
- PIC Microcontroller: PIC16F887
- Keypad: Connected to PORTB for input.
- LCD: Connected to PORTD for display.
- Seven-Segment Display: Connected to PORTC for displaying a countdown (30 to 0).
- Functions:
1. delay(int count):
   - Delays the program execution for a specified number of iterations.

2. pulse():
   - Generates a pulse on the EN (Enable) pin for the LCD.

3. type():
   - Initializes the LCD in 2-line mode.

4. on():
   - Turns on the LCD display.

5. address(int place):
   - Sets the LCD address for positioning the cursor.

6. data(char value):
   - Sends data to the LCD.

7. idisplay(char *sentence):
   - Displays a string on the LCD.

8. show(char *declined):
   - Displays a string when a call is declined.

9. show1(char *Busy):
   - Displays a string when the line is busy.

10. error(char *result):
    - Displays an error message.

11. keypad():
    - Reads input from the keypad and displays the corresponding number on the LCD.

Main Functionality:
- The program initializes the necessary ports and components.
- It sets up the LCD, displays an initial message, and waits for keypad input.
- The user can input a 10-digit phone number using the keypad.
- When the '#' key is pressed, the program initiates a countdown from 30 to 0 on the seven-segment display.
- If the 'C' key is pressed during the countdown, the program displays "Declined!"
- If the countdown reaches 0, the program displays "Busy!"
- If the phone number is not 10 digits, it displays "Invalid."

