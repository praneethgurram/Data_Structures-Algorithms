import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;

public class Bracket {
	Bracket(char type, int position) {
        this.type = type;
        this.position = position;
    }

    boolean Match(char c) {
        if (this.type == '[' && c == ']')
            return true;
        if (this.type == '{' && c == '}')
            return true;
        if (this.type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;


    public static void main(String[] args) throws IOException {
        InputStreamReader input_stream = new InputStreamReader(System.in);
        BufferedReader reader = new BufferedReader(input_stream);
        String text = reader.readLine();
        int pos=0,k = 0,count=0;
        Stack<Bracket> stack = new Stack<Bracket>();
        for (int position = 0; position < text.length(); ++position) {
            char next = text.charAt(position);
           
            if (next == '(' || next == '[' || next == '{') {
               
            	stack.push(new Bracket(next,position));
            	pos = position+1;
            }

            if (next == ')' || next == ']' || next == '}') {
               
            	if(stack.isEmpty())
            	{
            		k=1;
            		pos =position+1;
            		System.out.println(pos);
            		break;
            	}
            	
            	else
            	{
            		
            		Bracket br = stack.pop();
            		count++;
            		br = new Bracket(br.type,br.position);
            		if(!br.Match(next))
            		{
            			pos = position+1;
            			System.out.println(pos);
            			k=2;
            			break;
            		}
            		
            	}
            	
            }
            
        }
        if(stack.isEmpty() && k <=0)
        {
        	System.out.println("Success");
        }
        else
        {
        	if(k==0)
        		System.out.println(stack.peek().position+1);
        }
        
    }
}

