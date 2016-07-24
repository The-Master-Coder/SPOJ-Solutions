package spoj;

import java.util.*;

public class AMR12D {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        String x = input.nextLine();
        int t = Integer.parseInt(x);
        for (int i = 0; i < t; i++) {
            String s = input.nextLine();
            StringBuffer sb = new StringBuffer(s);
            String r = sb.reverse().toString();
            if (s.equals(r)) {
		System.out.println("YES");
            } else {
		System.out.println("NO");
            }
        }
    }
}
