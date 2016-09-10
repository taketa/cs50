#include <stdio.h>
#include <cs50.h>

int toCents(float i){
    int cents = (i * 1000)/10;
    return cents;
}
float checkPrice(){
    float price = GetFloat();
    while (price<0){
        printf("How much change is owed? $");
        price = GetFloat();
    }
    return price;
}
int change (float price, int coin){
    int current = price - coin;
    int sum = 0;
    while(current>=0){
        sum += 1;
        current -= coin;
    }
    return sum;
}
int main(){
    printf("Hi! How much change is owed? $");
    float centsPrice = toCents(checkPrice());
    int count = 0;
    while(centsPrice!=0){
        count += change(centsPrice, 25);
        centsPrice = centsPrice - change(centsPrice, 25)*25;
        count += change(centsPrice, 10);
        centsPrice = centsPrice - change(centsPrice, 10)*10;
        count += change(centsPrice, 5);
        centsPrice = centsPrice - change(centsPrice, 5)*5;
        count += change(centsPrice, 1);
        centsPrice = centsPrice - change(centsPrice, 1)*1;
    }
    printf("%i\n",count);
    return 0;
}