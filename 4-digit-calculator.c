#include <xc.h>
#include <stdio.h>
#define r0 RC0
#define r1 RC1
#define r2 RC2
#define r3 RC3
#define c0 RC4
#define c1 RC5
#define c2 RC6
#define c3 RC7

void lcdcmd(unsigned char);
void lcddata(unsigned char);
void disp_num(float num);
int get_num(char ch);
void lcdinit();
char scan_key(void);

unsigned char s[] = {"invalid input"};
unsigned char s1[] = {"Operator Expected"};
unsigned char s2[] = {"MATHS error"};
unsigned char s3[] = {" '=' Expected"};

void msdelay(int time) // Function for creating delay in milliseconds.
{
    unsigned i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 1275; j++)
            ;
}
void lcd_cmd(unsigned char command) // Function to send command instruction to LCD
{
    PORTB = command;
    PORTD = 0x04; // rs= 0,rw=0,e=1
    msdelay(1);
    PORTD = 0x00; // e=0;
}

void lcddata(unsigned char disp_data) // Function to send display data to LCD
{
    PORTB = disp_data; // rs= 1,rw=0,e=1;
    PORTD = 0x05;
    msdelay(1);
    PORTD = 0x01; // e=0
}
void start()
{
    main();
}

void lcd_init() // Function to prepare the LCD  and get it ready
{
    lcd_cmd(0x38); // for using 2 lines and 5X7 matrix of LCD
    msdelay(10);
    lcd_cmd(0x0F); // turn display ON, cursor blinking
    msdelay(10);
    lcd_cmd(0x01); // clear screen
    msdelay(10);
    lcd_cmd(0x80); // bring cursor to position 1 of line 0
    msdelay(10);
}
void delay(int cnt)
{
    while (cnt--)
        ;
}
int main()
{

    PORTD = 0;
    PORTB = 0;
    TRISD = 0x00;
    TRISB = 0x00;
    TRISC = 0xF0; // Rows Output, Columns  Input
    TRISB = 0x00; // Port-B as Output
    // TRISD6 = 0;   //Port-D PIN-6 as Output
    // TRISD7 = 0;   //Port-D PIN-7 as Output
    // msdelay(400); //400 nbr
    unsigned int count = 0;
    int k1, k2, k3, k4, k5, k6, k7, k8, k9;
    char a, b, c, d, e, f, g, h, i, j, k, key, equals;
    char on;
    // lcd_cmd(0x01); // to clear the screen
    // lcd_cmd(0x0c);  // to off the blinking cursor
    // on = scan_key();
    // if (on == 'c')
    // {
    lcd_init();

    while (1)
    {
        // count = 0;
        // lcd_cmd(0xC0); //to display on the seccond row
        // while (s4[count] != '\0') //Displaying String s on LCD
        //{

        // lcddata(s4[count]);
        // count++;
        //}

        a = scan_key(); // Scan the First Digit
        if (a == 'c')
        {
            lcd_cmd(0x01);
            lcd_cmd(0x80); // clear screen //clear screen
        }

        else if (a == '+' || a == '-' || a == '*' || a == '/' || a == '=')
        {
            count = 0;
            lcd_cmd(0xC0);           // to display on the seccond row
            while (s[count] != '\0') // Displaying String s on LCD
            {

                lcddata(s[count]);
                count++;
            }
        }
        else
        {

            k1 = get_num(a); // Converting Char into number
            b = scan_key();  // Scan the First Digit
            if (b == 'c')
            {
                lcd_cmd(0x01);
                lcd_cmd(0x80); // clear screen //clear screen
            }

            else if (b == '+' || b == '-' || b == '*' || b == '/' || b == '=')
            {
                count = 0;
                lcd_cmd(0xC0);           // to display on the seccond row
                while (s[count] != '\0') // Displaying String s on LCD
                {
                    lcddata(s[count]);
                    count++;
                }
            }
            else
            {

                k2 = get_num(b); // Converting Char into number
                c = scan_key();  // Scan the First Digit
                if (c == 'c')
                {
                    lcd_cmd(0x01);
                    lcd_cmd(0x80); // clear screen //clear screen
                }

                else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=')
                {
                    count = 0;
                    lcd_cmd(0xC0);           // to display on the seccond row
                    while (s[count] != '\0') // Displaying String s on LCD
                    {
                        lcddata(s[count]);
                        count++;
                    }
                }
                else
                {
                    k3 = get_num(c); // Converting Char into number

                    d = scan_key(); // Scan the First Digit

                    if (d == 'c')
                    {
                        lcd_cmd(0x01);
                        lcd_cmd(0x80); // clear screen //clear screen
                    }

                    else if (d == '+' || d == '-' || d == '*' || d == '/' || d == '=')
                    {
                        count = 0;
                        lcd_cmd(0xC0);           // to display on the seccond row
                        while (s[count] != '\0') // Displaying String s on LCD
                        {
                            lcddata(s[count]);
                            count++;
                        }
                    }
                    else
                    {

                        k4 = get_num(d); // Converting Char into number
                        int num1 = (k1 * 1000) + (k2 * 100) + (k3 * 10) + k4;
                        lcddata(' ');
                        key = scan_key(); // Scaning operator
                        lcddata(' ');

                        if (key == 'c')
                        {
                            lcd_cmd(0x01);
                            lcd_cmd(0x80); // clear screen //clear screen
                        }

                        else if (key == '0' || key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9')
                        {
                            count = 0;
                            lcd_cmd(0xC0);            // to display on the seccond row
                            while (s1[count] != '\0') // Displaying String s on LCD
                            {
                                lcddata(s1[count]);
                                count++;
                            }
                        }
                        else
                        {
                            e = scan_key(); // Scan the First Digit

                            if (e == 'c')
                            {
                                lcd_cmd(0x01);
                                lcd_cmd(0x80); // clear screen //clear screen
                            }

                            else if (e == '+' || e == '-' || e == '*' || e == '/' || e == '=')
                            {
                                count = 0;
                                lcd_cmd(0xC0);           // to display on the seccond row
                                while (s[count] != '\0') // Displaying String s on LCD
                                {
                                    lcddata(s[count]);
                                    count++;
                                }
                            }
                            else
                            {
                                k5 = get_num(e); // Converting Char into number
                                f = scan_key();  // Scan the First Digit
                                if (f == 'c')
                                {
                                    lcd_cmd(0x01);
                                    lcd_cmd(0x80); // clear screen //clear screen
                                }

                                else if (f == '+' || f == '-' || f == '*' || f == '/' || f == '=')
                                {
                                    count = 0;
                                    lcd_cmd(0xC0);           // to display on the seccond row
                                    while (s[count] != '\0') // Displaying String s on LCD
                                    {
                                        lcddata(s[count]);
                                        count++;
                                    }
                                }
                                else
                                {

                                    k6 = get_num(f); // Converting Char into number

                                    g = scan_key(); // Scan the First Digit
                                    if (g == 'c')
                                    {
                                        lcd_cmd(0x01);
                                        lcd_cmd(0x80); // clear screen //clear screen
                                    }

                                    else if (g == '+' || g == '-' || g == '*' || g == '/' || g == '=')
                                    {
                                        count = 0;
                                        lcd_cmd(0xC0);           // to display on the seccond row
                                        while (s[count] != '\0') // Displaying String s on LCD
                                        {
                                            lcddata(s[count]);
                                            count++;
                                        }
                                    }
                                    else
                                    {
                                        k7 = get_num(g); // Converting Char into number
                                        h = scan_key();  // Scan the First Digit
                                        if (h == 'c')
                                        {
                                            lcd_cmd(0x01);
                                            lcd_cmd(0x80); // clear screen //clear screen
                                        }

                                        else if (h == '+' || h == '-' || h == '*' || h == '/' || h == '=')
                                        {
                                            count = 0;
                                            lcd_cmd(0xC0);           // to display on the seccond row
                                            while (s[count] != '\0') // Displaying String s on LCD
                                            {
                                                lcddata(s[count]);
                                                count++;
                                            }
                                        }
                                        else
                                        {
                                            k8 = get_num(h); // Converting Char into number
                                            int num2 = (k5 * 1000) + (k6 * 100) + (k7 * 10) + k8;
                                            lcddata(' ');
                                            equals = scan_key();

                                            if (equals == 'c')
                                            {
                                                lcd_cmd(0x01);
                                                lcd_cmd(0x80); // clear screen //clear screen
                                            }

                                            else if (equals != '=')
                                            {
                                                count = 0;
                                                lcd_cmd(0xC0);            // to display on the seccond row
                                                while (s3[count] != '\0') // Displaying String s on LCD
                                                {
                                                    lcddata(s3[count]);
                                                    count++;
                                                }
                                            }
                                            else
                                            {
                                                // lcd_cmd(0x82); //Start displying data on lcd at position Row=1 Coulomb=3
                                                count = 0;
                                                count = 0;
                                                lcd_cmd(0xC0); // Jump to second Line of Lcd
                                                lcddata(' ');
                                                lcddata('=');
                                                switch (key)
                                                {
                                                case '+':
                                                {
                                                    int count = 0;
                                                    int disp_num = num1 + num2;
                                                    char str[8];
                                                    sprintf(str, "%d", disp_num);
                                                    // lcddata(str);
                                                    while (str[count] != '\0') // Displaying String s on LCD
                                                    {
                                                        lcddata(str[count]);
                                                        count++;
                                                    }
                                                }
                                                break;
                                                case '-':
                                                {
                                                    int count = 0;
                                                    int disp_num = num1 - num2;
                                                    char str1[8];
                                                    sprintf(str1, "%d", disp_num);
                                                    while (str1[count] != '\0') // Displaying String s on LCD
                                                    {
                                                        lcddata(str1[count]);
                                                        count++;
                                                    }
                                                }
                                                break;
                                                case '*':
                                                {
                                                    int count = 0;
                                                    long int nu1 = num1;
                                                    long int nu2 = num2;
                                                    long int disp_num2 = (nu1 * nu2);
                                                    char str2[12];
                                                    sprintf(str2, "%ld", disp_num2);
                                                    while (str2[count] != '\0') // Displaying String s on LCD
                                                    {
                                                        lcddata(str2[count]);
                                                        count++;
                                                    }
                                                }
                                                break;
                                                case '/':
                                                {
                                                    int count = 0;
                                                    float x = num1;
                                                    float y = num2;
                                                    if (num2 == 0)
                                                    {
                                                        count = 0;
                                                        lcd_cmd(0xC0);            // to display on the seccond row
                                                        while (s2[count] != '\0') // Displaying String s on LCD
                                                        {
                                                            lcddata(s2[count]);
                                                            count++;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        float disp_num = x / y;
                                                        char str3[8];
                                                        sprintf(str3, "%.4f", disp_num);
                                                        while (str3[count] != '\0') // Displaying String s on LCD
                                                        {
                                                            lcddata(str3[count]);
                                                            count++;
                                                        }
                                                    }
                                                    break;
                                                }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
//}
char scan_key() // Scan the Pressed Key by user
{
    unsigned char c = 's';
    while (c != 'a')
    {
        r0 = 1;
        r1 = 0;
        r2 = 0;
        r3 = 0;
        if (c0 == 1 && r0 == 1)
        {
            lcddata('7');
            msdelay(70);
            return '7';
            c = 'a';
        }
        if (c1 == 1 && r0 == 1)
        {
            lcddata('8');
            msdelay(70);
            return '8';
            c = 'a';
        }
        if (c2 == 1 && r0 == 1)
        {
            lcddata('9');
            msdelay(70);
            return '9';
            c = 'a';
        }
        if (c3 == 1 && r0 == 1)
        {
            lcddata('/');
            msdelay(70);
            return '/';
            c = 'a';
        }
        r0 = 0;
        r1 = 1;
        r2 = 0;
        r3 = 0;
        if (c0 == 1 && r1 == 1)
        {
            lcddata('4');
            msdelay(70);
            return '4';
            c = 'a';
        }
        if (c1 == 1 && r1 == 1)
        {
            lcddata('5');
            msdelay(70);
            return '5';
            c = 'a';
        }
        if (c2 == 1 && r1 == 1)
        {
            lcddata('6');
            msdelay(70);
            return '6';
            c = 'a';
        }
        if (c3 == 1 && r1 == 1)
        {
            lcddata('*');
            msdelay(70);
            return '*';
            c = 'a';
        }
        r0 = 0;
        r1 = 0;
        r2 = 1;
        r3 = 0;
        if (c0 == 1 && r2 == 1)
        {
            lcddata('1');
            msdelay(70);
            return '1';
            c = 'a';
        }
        if (c1 == 1 && r2 == 1)
        {
            lcddata('2');
            msdelay(70);
            return '2';
            c = 'a';
        }
        if (c2 == 1 && r2 == 1)
        {
            lcddata('3');
            msdelay(70);
            return '3';
            c = 'a';
        }
        if (c3 == 1 && r2 == 1)
        {
            lcddata('-');
            msdelay(70);
            return '-';
            c = 'a';
        }
        r0 = 0;
        r1 = 0;
        r2 = 0;
        r3 = 1;
        if (c0 == 1 && r3 == 1)
        {
            lcddata('|');
            msdelay(70);
            return 'c';
            c = 'a';
        }
        if (c1 == 1 && r3 == 1)
        {
            lcddata('0');
            msdelay(70);
            return '0';
            c = 'a';
        }
        if (c2 == 1 && r3 == 1)
        {
            lcddata('=');
            msdelay(70);
            return '=';
            c = 'a';
        }
        if (c3 == 1 && r3 == 1)
        {
            lcddata('+');
            msdelay(70);
            return '+';
            c = 'a';
        }
    }
    return 0;
}

int get_num(char ch) // converting character into integer
{
    switch (ch)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    }
    return 0;
}
