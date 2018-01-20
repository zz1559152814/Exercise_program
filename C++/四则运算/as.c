import java.util.Scanner;  
import java.util.Stack;  
  
public class Operation_Stack 
{  
    public static void main(String[] args) 
    {  
        Scanner scan = new Scanner(System.in);  
        Stack<Double> number = new Stack<Double>(); 
        Stack<Integer> operator = new Stack<Integer>(); 
        double n, left_number, right_number, result = 0;  
        boolean bracket_clear;
        int op, read_data;
        bracket_clear = true;
        System.out.print("Input:  ");
        while(scan.hasNext()) 
        {
        	n = scan.nextInt();
        	if(isNumber())
        		number.push(n);
        	else if(isOpeator(n))
                operator.push(n);
            else if(isLeftbracket(n))
            {
                operator.push(n);
                bracket_clear = false;
            }
            else if(isRightbracket(n))
                bracket_clear = true;

            if(bracket_clear)
            {
                while(!operator.empty())
                {
            		right_number = number.pop();
            		left_number = number.pop();
            		switch(operator.pop())
            		{
            			case (int) '+': result = left_number + right_number; break;
            			case (int) '-': result = left_number - right_number; break;
            			case (int) '*': result = left_number * right_number; break;
            			case (int) '/': result = left_number / right_number; break;
            			case (int) '^': 
                            result = 1;
                            for(int counter = right_number; counter <= 0; counter--)
                                result *= left_number;
                            break;
                        default: break;
            		}
                    number.push(result);
                }
        	}
        }
        System.out.print('\n' + "Result: " + number.pop());
    }  
    private static boolean isNumber(int temp) 
    {  
        if(temp > '0' && temp <'9')
            return true;
        else  
            return false;  
    }
    private static boolean isOpeator(int temp) 
    {  
        if(temp == '+' || temp == '-' || temp == '*' || temp == '/')
            return true;
        else  
            return false;  
    }
    private static boolean isLeftbracket(int temp) 
    {  
        if(temp == '(')
            return true;
        else  
            return false;  
    }
    private static boolean isRightbracket(int temp) 
    {  
        if(temp == ')')
            return true;
        else  
            return false;  
    }
}  
