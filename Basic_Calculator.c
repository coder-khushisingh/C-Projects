#include<stdio.h>
int main()
{
    double num1,num2,result;
    char op;

    printf("\n Enter Operator (+,-,*,/):");
    scanf("%c",&op);
    printf("\n Enter Two numbers:");
    scanf("%lf%lf",&num1,&num2);

    switch(op)
    {
        case '+':
        result=num1+num2;
        break;
        case '-':
        result=num1-num2;
        break;
        case '*':
        result=num1*num2;
        break;
        case'/':
        if(num2!=0)
            result=num1/num2;
        else
        {
            printf("Error! Division by zero.\n");
            return 1;
        
        }
        break;
        default:
            printf("Error!Operator is not correct\n");
            return 1;
    }
    
    printf("%2lf %c %2lf=%2lf\n",num1,op,num2,result);
    return 0;

}