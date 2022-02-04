// Program that finds the smallest prime which, by replacing part of the
// number with the same digit, is part of an eight prime value family.

#include <stdio.h>
#include <math.h>

int isprime(int num);
long quick_pow10(int power);

int main() 
{
    int l = 3; 
    long ans = -1;
    unsigned int digs;
    while(ans < 0) {
        for(digs=1; (digs<(1 << (l-1))) && (ans < 0); digs++) {
            unsigned int reps = digs << 1;
            int onecount = 0;
            int ones[l];
            int i;
            int bit;
            long g;
            for(i=l - 1; i >= 0; i -= 1) {
                bit = (reps >> i) & 1;
                if(bit == 1) {
                    ones[onecount++] = l - 1 - i;
                }
            }
            for(g = quick_pow10(l-1-onecount) + ((l-1-onecount)>0);
               (g < quick_pow10(l-onecount)) && (ans < 0);
                g+=2) {
                int t;
                int primecount = 0;
                int failcount = 0;
                int gdc = 0;
                int tni;
                long testnum = 0;
                long testnumt;
                for(tni=0; tni < l; tni++) {
                    if(!((reps >> tni) & 1)) {
                        testnum += 
                        ((g / quick_pow10(gdc++)) % 10) * 
                        quick_pow10(tni);
                    }
                }
                for(t=9; t >= (int)((reps >> (l - 1)) & 1); t--) {
                    testnumt = testnum;
                    int k;
                    for(k=0; k < onecount; k++){
                        testnumt += t * quick_pow10(l - 1 - ones[k]);
                    }

                    if(isprime(testnumt)) {
                        primecount += 1;
                    } 
                    else {
                        if((++failcount) >= 3) {
                            break;
                        }
                    }
                }

                if(primecount >= 8) {
                    ans = testnumt;
                } 
            }
        }
        l++;
    }
    printf("%ld\n", ans);
}


long quick_pow10(int power)
{
    static long pow10[11] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000, 10000000000
    };

    return pow10[power];
}


int isprime(int num)
{
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < num / 2; i+= 2)
     {
         if (num % i == 0)
             return 0;
     }
     return 1;
}
