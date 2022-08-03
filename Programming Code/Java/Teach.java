import java.io.*;

public class Teach{
    public static void main(String[] args) throws IOException{
        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(in);

        String s = br.readLine();
        System.out.print("hello, " + s );
    }
}