//求2和n的最小公倍数
int smallestEvenMultiple(int n) {
    if(n%2==0)
    return n;
    else
    return n*2;
}

//官方答案：return n % 2 == 0 ? n : 2 * n;