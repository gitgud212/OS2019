/**
 * @file testcases.c
 * @provides testcases
 *
 * $Id: testcases.c 175 2008-01-30 01:18:27Z brylow $
 *
 * Modified by:
 *
 * and
 *
 */
/* Embedded XINU, Copyright (C) 2007.  All rights reserved. */

#include <xinu.h>

devcall putc(int dev, char c)
{
    return 0;
}


/**
 * testcases - called after initialization completes to test things.
 */
void testcases(void)
{
    int c;

    kprintf("===TEST BEGIN===\r\n");

    c = kgetc();
    switch (c)
    {
	case 'a':
		kprintf("hey man hows the family?\r\n");		
		break;
	case 'b':	//put a char, test if it is available, if so, print char
		kputc('e');
		if (kcheckc()== 1)
			kprintf("%d\r\n",kgetc());
		break;
	case 'c':	//this should return 99/some error because the register is empty
		kprintf("%d\r\n",kgetc());
		break;
	case 'd':	// this should return 0 because the register is empty
		kprintf("%d\r\n",kcheckc());
		break;
	case 'e':	//this should return e then 0 becaue it puts e and then the register is still empty
		kputc('e');
		kprintf("%d\r\n",kcheckc());
		break;
	case 'f':	//adds chars w,i,n to the register and prints them out
		kputc('w');
		kputc('i');
		kputc('n');
		while (kcheckc()==1)
			kprintf("%d\r\n",kgetc());
		break;
	case 'g':	//should just place the char in the buffer and return h
		kputc('h');
		kungetc('h');	
		break;
	
        // TODO: Test your operating system!

    default:
        kprintf("Hello Xinu World!\r\n");
    }


    kprintf("\r\n===TEST END===\r\n");
    return;
}
