import java.net.*;
import java.io.*;
import java.util.*;
class DateServer{
   
   public static void main(String args[]) throws Exception{ 
      ServerSocket s = new ServerSocket(9999);
          while(true){ 
      
            System.out.println(“ Connection Pending... “);
            Socket soc = s.accept();
             
            DataOutputStream out = new DataOutputStream(soc.getOutputStream());
            out.writeBytes(“Date: “ + (new Date()).toString() + “\n”);
             
            out.close();
            soc.close();
      
           }
      }
}
