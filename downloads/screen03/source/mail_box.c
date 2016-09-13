#include <sys/types.h>
/* Base address of mail box */
#define MAIL_BOX_BASE 0x2000B880

void MailboxWrite(int value, int channel);

/* 
* MailboxWrite writes the value given in the top 28 bits of value to the channel
* given in the low 4 bits of channel.
*/
void MailboxWrite(int value, int channel){
	int result = value & 0b1111, status;
	if( result != 0 && channel > 15 ){
		return;
	}
	int mailBoxBase = MAIL_BOX_BASE;
	result = 1;
	while( result != 0 ){
		status = *((unsigned int*)(mailBoxBase+0x18));
		result = status & 0x80000000;
	}
	value = value + channel;
	*((unsigned int*)(mailBoxBase+0x20)) = value;
}


/* 
* MailboxRead returns the current value in the mailbox addressed to a channel
* given in the low 4 paramater channel, as the top 28 bits of paramater channel.
*/
int MailboxRead(int channel){
	int inChannel, result, mail, status;
	if( channel > 15 ){
		return 1;
	}
	int mailBoxBase = MAIL_BOX_BASE;
	while( inChannel != channel ){
		while( result != 0 ){
			status = *((unsigned int*)(mailBoxBase+0x18));
			result = status & 0x40000000;
		}
		mail = *((unsigned int*)(mailBoxBase+0));
		inChannel = mail & 0b1111;
	}
	result = mail & 0xfffffff0;
	return result;
}
