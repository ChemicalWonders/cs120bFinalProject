#ifndef __BIT_H_
#define __BIT_H_

/*** SET/GET Bit***/
//x is the word to be modified, k-th bit to modify, b is the new bit
unsigned char SetBit(unsigned char x, unsigned char k, unsigned b){
	return(b?x|(0x01<<k):x&~(0x01<<k) );
}

//x is the word to access, k-th bit to get
unsigned char GetBit(unsigned char x, unsigned char k){
	return((x&(0x01<<k))!=0);
}


#endif