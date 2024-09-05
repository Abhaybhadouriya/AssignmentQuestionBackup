// Roll no :- MT2024003
// Name :- Abhay Bhadouriya
// 19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
#include <stdio.h>
#include <unistd.h>  // For getpid()

// this function will read CPU time stamp counter - this counter is a 64 bit register
// that increment with each clock cycle - aka timestamp counter (TSC). 
// it count the #cpu cycle since last reset.
// Location :- hardware -> TSC is located within each CPU core. 
//                         it is a part of cpu control and status register (CSRs)
//                         it is accessed via "rdtsc" (Read time Stamp counter) assembly instruction
//             Accessing : 1) using "RDTSC" instruction x86 assembly language
//                           this instruction loads the current value of TSC into EDX:EAX pair of integer in 64 bit mode
//                         2) in C instruction is accessed through inline assembly,
unsigned long long rdtsc(){
    // TSC give us 64 bit code but unsigend int can only hold 32 bit. so it will store in 2 variable
    unsigned int lo, hi;
    // __asm__ it used to insert the assembly language code directlr within the c program aka- inline assembly
    // __volatile__ it prevents the compiler ot to optimize away this assembly code, ensuring that it is executed exactly as written. 
    //          and  the value of the variable will not change unexpectedly.
    // "rdtsc" - it reads the current value of TSC into two register 
    //            1. EAX -  will hold lower 32 bit of TSC
    //            2. EDX - hold upper 32 bith
    //        =a,=d means the value present in EAX and EDX store in lo an hi
    //      now shifting hi value by 32 bit so making it as upper hafl
    //       and using | 'or' operator combine both lo and hi
    __asm__ __volatile__ (
        "rdtsc"
        : "=a" (lo), "=d" (hi)
    );
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;

    // get the time before calling getpid() function
    start = rdtsc();

    // Execute the getpid() system call
    getpid();

    // Get time time after calling getpid() function
    end = rdtsc();

    // now calculate the diffence between start and end, and this is the answer
    printf("getpid() takes : %llu cycles\n", end - start);

    return 0;
}
