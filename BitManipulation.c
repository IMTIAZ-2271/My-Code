#include<stdio.h>
#include<stdlib.h>
int is_positive(int n){
    if((n>>31)&1)return 0;
    return 1;
}
int is_negative(int n){
    return (n&(1<<31))>>31;
}
int is_equal(int a,int b){
    if(a^b)return 0;
    return 1;
}
int is_greater(int a,int b){
    int diff = a-b;
    if(a^b){
        if((diff&(1<<31))>>31)return -1;
        return 1;
    }
    return 0;
}
int is_smaller(int a , int b){
    int diff = a-b;
    if(a^b){
        if((diff>>31)&1)return 1;
        return -1;
    }
    return 0;
}
int swap_pair_bit(int n){
    int ans = 0;
    for(int i = 0; i<32; i+=2){
        int even_bit = (n&(1<<i))<<1;
        int odd_bit = (n&(1<<(i+1)))>>1;
        ans |= even_bit;
        ans |= odd_bit;
    }
    return ans;
}
int swap_number(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
int make_negative(int n){
    if(n>0)return (~n)+1;
}
int get_ith_bit(int n, int i){
    return (n&(1<<i))>>i;
}
int set_ith_bit(int n, int i){
    return n | (1<<i);
}
int clear_ith_bit(int n, int i){
    return n & (~(1<<i));
}
int flip_ith_bit(int n, int i){
    return n ^ (1<<i);
}
int set_n_bits_from_i(int n, int i, int bits){
    int mask = (1<<bits)-1;
    mask = mask<<i;
    return n | mask;
}
int clear_n_bits_from_i(int n, int i, int bits){
    int mask = (1<<bits)-1;
    mask = mask<<i;
    mask = ~mask;
    return n & mask;
}
int flip_n_bits_from_i(int n, int i, int bits){
    int mask = (1<<bits)-1;
    mask = mask<<i;
    return n ^ mask;
}
int rotate_left(int n, int d){
    return (n<<d) | (n>>(32-d));
}
int rotate_right(int n, int d){
    return (n>>d) | (n<<(32-d));
}
int count_set_bits(int n){
    int count = 0;
    while(n){
        n = n&(n-1);
        count++;
    }
    return count;
}
int count_unset_bits(int n){
    int cnt_set = 0;
    while(n){
        n&=(n-1);
        cnt_set++;
    }
    return 32-cnt_set;
}
int trailing_zeroes(int n){
    if(n == 0) return 0;
    int count = 0;
    while((n&1) == 0){
        count++;
        n = n>>1;
    }
    return count;
}
int leading_zeroes(int n){
    if(n == 0) return 32;
    int count = 0;
    for(int i = 31; i>=0; i--){
        if((n&(1<<i)) == 0)count++;
        else break;
    }
    return count;
}
int rotate_left_m_bits_from_i(int n, int i, int m, int d){
    d = d % m;
    int mask = ((1<<m)-1)<<i;
    int temp = n&(mask);
    temp = (temp<<d)|(temp>>(m-d));
    n = n&(~mask);
    mask = mask&temp;
    n = n|mask;
    return n;
}
int rotate_right_m_bits_from_i(int n, int i, int m, int d){
    d = d % m;
    int mask = ((1<<m)-1)<<i;
    int temp = n&(mask);
    temp = (temp>>d)|(temp<<(m-d));
    n = n&(~mask);
    mask = mask&temp;
    n = n|mask;
    return n;
}
int is_power_of_two(int n){
    if(n<0)return 0;
    if(n&(n-1))return 0;
    return 1;
}
int is_power_of_four(int n){
    if(n<0)return 0;
    if(n == 0)return 1;
    int cnt = 0;
    while(n>1){
        if(n&1)return 0;
        n = n>>1;
        cnt++;
    }
    if(cnt%2 == 0 && n == 1)return 1;
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("is_positive: %d\n",is_positive(n));
    printf("is_negative: %d\n",is_negative(n));
    int m;
    scanf("%d",&m);
    printf("is_equal: %d\n",is_equal(n,m));
    printf("is_greater: %d\n",is_greater(n,m));
    printf("is_smaller: %d\n",is_smaller(n,m));
    printf("swap_pair_bit: %d\n",swap_pair_bit(n));
    swap_number(&n,&m);
    printf("After swapping n: %d m: %d\n",n,m);
    printf("make_negative: %d\n",make_negative(n));
    int i;
    scanf("%d",&i);
    printf("get_ith_bit: %d\n",get_ith_bit(n,i));
    printf("set_ith_bit: %d\n",set_ith_bit(n,i));
    printf("clear_ith_bit: %d\n",clear_ith_bit(n,i));
    printf("flip_ith_bit: %d\n",flip_ith_bit(n,i));
    int bits;
    scanf("%d",&bits);
    printf("set_n_bits_from_i: %d\n",set_n_bits_from_i(n,i,bits));
    printf("clear_n_bits_from_i: %d\n",clear_n_bits_from_i(n,i,bits));
    printf("flip_n_bits_from_i: %d\n",flip_n_bits_from_i(n,i,bits));
    int d;
    scanf("%d",&d);
    printf("rotate_left: %d\n",rotate_left(n,d));
    printf("rotate_right: %d\n",rotate_right(n,d));
    printf("count_set_bits: %d\n",count_set_bits(n));
    printf("count_unset_bits: %d\n",count_unset_bits(n));
    printf("trailing_zeroes: %d\n",trailing_zeroes(n));
    printf("leading_zeroes: %d\n",leading_zeroes(n));
    int m_bits;
    scanf("%d",&m_bits);
    scanf("%d",&d);
    printf("rotate_left_m_bits_from_i: %d\n",rotate_left_m_bits_from_i(n,i,m_bits,d));
    scanf("%d",&d);
    printf("rotate_right_m_bits_from_i: %d\n",rotate_right_m_bits_from_i(n,i,m_bits,d));
    printf("is_power_of_two: %d\n",is_power_of_two(n));
    printf("is_power_of_four: %d\n",is_power_of_four(n));
}   
