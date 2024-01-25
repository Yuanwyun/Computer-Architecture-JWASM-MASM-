/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int overflow, underflow;
int swp = 0;                //set pointer swp is equal to 0;
int cwp = 0;                // set pointer cwp is equal to 0;
int calls = 0;            
int stack = 0;              //set the num of registers in stack is 0;
int result;

void underflow_check(){
    cwp--;                  //cwp is decrese each time when we return a function
    if (cwp<0){             //if cwp is smaller than 0, set cwp to 7
        cwp = 7;
    }
    if (cwp == swp && stack>0){     //when cwp is equal to swp at the same time there are registers in the stack(underflow occured)
        swp --;                     //swp -1
        if (swp<0){                 //if swp is smaller than 0, set swp to 7
            swp = 7;
        }
        underflow++;                //underflow+1
        stack--;                    //the number of registers in stack decrease
    }
    
}

int ack3way(int m, int n, int p){
    calls++;
    cwp ++;                 //cwp pointer +1 everytime when a function call occured
    if (cwp >7){            //when cwp pointer greater than 7, 
        cwp = 0;            //set cwp to 0
    }
    if (cwp == swp){        //when cwp = swp;overflow accure
        swp ++;             //swp move down, swp +1
        if (swp >7){        //if swp is greater than 7;
            swp = 0;        //swp set to 0;
        }
        overflow++;         //overflow++
        stack++;            //the register in stack ++
        }
    
    if (p==0) {             
        underflow_check();      //everytime before return, we check underflow,cause underflow only occure after return.
        
        return m+n;
    }
    if (n==0 && p==1) {
        underflow_check();      //check underflow before return
        
        return 0;
    }
    if (n==0 && p==2) {
        underflow_check();      //check underflow before return
        
        return 1;
    }
    if (n==0) {
        underflow_check();      //check underflow before return
        
        return m;
    }
    else
        
        result = ack3way(m, ack3way(m, n-1,p),p-1);
        underflow_check();     //check underflow before return
        return result;
}

int main(){
    
    printf("Result: %d\n", ack3way(2,3,3));
    printf("number of function calls: %d\n", calls);
    printf("overflow: %d\n", overflow);
    printf("underflow: %d\n", underflow);
    printf("stack: %d\n", stack);
    printf("CWP: %d || SWP: %d ",cwp, swp);
    return 0;
}


