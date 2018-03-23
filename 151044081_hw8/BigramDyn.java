import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.*;

public class BigramDyn<T> implements Bigram<T> {
    
    private final int dataType;
    
    private int k = 0;
    
    private Scanner input;
    
    private DynamicArray<T> [] dyn ;
    
    private T [] array;
    
    private int capacity = 50 ;
    
    private int numberOfLines = 0 ;
    
    public static boolean isInteger(String s) {
        
        try { 
            Integer.parseInt(s); 
        } 
        catch(NumberFormatException e){
            
            return false; 
        }
        catch(NullPointerException e){
            
            return false; 
        }
        
        return true;
    }
    
    public static boolean isDouble(String s) {
        
        try { 
            Double.parseDouble(s); 
        } 
        catch(NumberFormatException e){
            
            return false; 
        }
        catch(NullPointerException e){
            
            return false; 
        }
    
        return true;
    }
    
    public BigramDyn(int _dataType){
        
        this.dataType = _dataType;
        
        this.array = (T[]) new Object[capacity];   
        
		this.dyn = new DynamicArray[capacity];
    }
    
    @Override
    public void readFile(String filename) throws myException{
        
        try{

            File file = new File(filename);

            if(file.length() < 3){

                throw new myException("Empty File");
            }
        
            input = new Scanner(new File (filename) );
            
            BufferedReader reader = null;
            
            reader = new BufferedReader(new FileReader(filename));
            
            String line = reader.readLine();
            
            if (numberOfLines >= capacity){

                capacity *= 2;

                T[] a = (T[]) new Object[capacity];

                for (int j = 0 ; j < numberOfLines ; j++){

                    a[j] = array[j];
                }

                for (int k = 0 ; k < numberOfLines ; k++){

                    array[k] = a[k];

                }

            }
 
            for (String retval: line.split(" ")) {

                if(dataType == 1){
                    
                    if(isInteger(retval)){
                    
						array[numberOfLines] = (T)new Integer(retval);

 
                    }
                    else{

                        throw new myException("Bad data for int");

                    }

                }
                else if (dataType == 3){
                    
                    if(isDouble(retval)){
                        
						array[numberOfLines] = (T)new Double(retval);
                    }

                    else{

                        throw new myException("Bad data for double");
                    }
                }else{
        
					array[numberOfLines] = (T) retval;
                }
                
                numberOfLines++;

            }// end for

            		
            for (int i = 0 ; i < numberOfLines - 1 ; i++){

                boolean flag = true;

                for (int j = 0; j < k ; j++){
                
                    if ((array[i].equals(dyn[j].geta())) && (array[i + 1].equals(dyn[j].getb()))){

                        dyn[j].setvalue(dyn[j].getvalue() + 1);

                        flag = false;
                    }
                }

                if (flag == true){
					
					dyn[k] = new DynamicArray<T>();
                
                    dyn[k].seta(array[i]);

                    dyn[k].setb(array[i + 1]);

                    dyn[k].setvalue(1);

                    k++;

                }

            }//end for


        }
        catch(FileNotFoundException fileNotFoundException){
            
            System.err.println("File could not found");        
        }
        catch(IOException ioException){
            
            System.err.println("File could not found");        
        }
    }//end of function
    
    @Override
    public int numGrams(){

        return numberOfLines-1;
    }
   
    @Override
    public int numOfGrams(T var1,T var2){

        for (int i = 0 ; i < k ; i++){

            if (dyn[i].geta().equals(var1) && dyn[i].getb().equals(var2)){

                return dyn[i].getvalue();
            }
        }
	return 0;
    }
    
    @Override
    public String toString(){
    
		StringBuilder result = new StringBuilder();
        
        int max = dyn[0].getvalue();
        
        T str1 = dyn[0].geta();
        
        T str2 = dyn[0].getb();
        
        for (int i = 0 ; i < k; i++){

            if (dyn[i].getvalue() > max){

                max = dyn[i].getvalue();

                str1 = dyn[i].geta();

                str2 = dyn[i].getb();
            }
        }

        for (int max1=max ; max1 > 0 ; max1--){

            for (int i = 0 ; i < k ; i++){

                if (max1 == dyn[i].getvalue()){
                    
                    result.append("first.first: "+dyn[i].geta()+" first.second: "+dyn[i].getb()+" second : "+dyn[i].getvalue() + "\n");
                }

            }
        }

        return result.toString();
    
    }
}
