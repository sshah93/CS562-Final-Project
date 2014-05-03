import java.sql.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class assignment1 {

    String usr ="postgres";
    String pwd ="xxxxxxx";
    String url ="jdbc:postgresql://localhost:5432/skim2";
    String cust_name,product;
    int day,month,year,quant,flag=0;
    


    public static void main(String[] args) {
        
        assignment1 dbmsass1 = new assignment1();
        dbmsass1.connect();
        dbmsass1.retreive();
    }

    //Function to connect to the database

    void connect(){
        try {
        Class.forName("org.postgresql.Driver");     //Loads the required driver
        System.out.println("Success loading Driver!");
        } catch(Exception exception) {
        System.out.println("Fail loading Driver!");
        exception.printStackTrace();
        }
    }

    //Function to retreive from the database and process on the resultset received

    void retreive(){

        try {
        Connection con = DriverManager.getConnection(url, usr, pwd);    //connect to the database using the password and username
        System.out.println("Success connecting server!");
        ResultSet rs;          			 //resultset object gets the set of values retreived from the database
        boolean more;
        int i=1,j=0;
        Statement st = con.createStatement();   //statement created to execute the query
        String ret = "select * from sales";
        rs = st.executeQuery(ret);              //executing the query 
        more=rs.next();                         //checking if more rows available
        System.out.printf("%-8s","Customer  ");             //left aligned
        System.out.printf("%-7s","Product  ");              //left aligned
        System.out.printf("%-5s","Day    " +
        		"");                //left aligned
        System.out.printf("%-10s","Month    ");          //left aligned
        System.out.printf("%-5s","Year   ");                //left aligned
        System.out.printf("%-10s","State    ");          //left aligned
        System.out.printf("%-5s%n","Quant  ");              //left aligned
        System.out.println("========  =======  =====  ========  =====  ========  =====");
        while(more)
        {
        	System.out.printf("%-8s  ",rs.getString(1));            //left aligned
            System.out.printf("%-7s  ",rs.getString(2));            //left aligned
            System.out.printf("%5s  ",rs.getInt(3));             //right aligned
            System.out.printf("%8s  ",rs.getInt(4));            //right aligned
            System.out.printf("%5s  ",rs.getInt(5));             //right aligned
            System.out.printf("%-8s  ",rs.getString(6));            //right aligned
            System.out.printf("%5s%n",rs.getString(7));   //right aligned
            
        	more=rs.next();
        }
        } catch(SQLException e) {
         System.out.println("Connection URL or username or password errors!");
        e.printStackTrace();
        }
    }
}
