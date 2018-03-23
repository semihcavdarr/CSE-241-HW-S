import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.*;

public class BigramMap<T> implements Bigram<T> {
    
    private final int dataType ;
    
    private HashMap<Pair<T,T>,Integer> mymap;
    
    private Scanner input;
    
    private int countForNumGrams = 0;

    private Pair<T,T> [] peyir;

    private int capacity = 50 ;
    
    private ArrayList<T> array ;
    
    public BigramMap(int _dataType){
        
        this.dataType = _dataType;

        this.array = new ArrayList<>();

        this.mymap = new HashMap<>();

      //  this.peyir = new Pair[capacity];
    }
    
    public static boolean isInteger(String s) {
        
        try { 
            Integer.parseInt(s); 
        } 
		catch(NumberFormatException e) { 
        
            return false; 
        }
        catch(NullPointerException e) { 
        
            return false; 
        }
        
        return true;
    }
    
    public static boolean isDouble(String s) {
        
        try { 
            Double.parseDouble(s); 
        } 
        catch(NumberFormatException e) { 
        
            return false; 
        }
        catch(NullPointerException e) { 
        
            return false; 
        }
    
        return true;
    }
    
    /**
     *
     * @param filename
     */
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
            
            for (String retval: line.split(" ")) {
                
                if(dataType == 1){
                    
                    if(isInteger(retval)){
 
						array.add((T)new Integer(retval));
                     }

                    else{

                        throw new myException("Bad data for int");

                    }

                }else if (dataType == 2){
                
					array.add((T)retval);
					                
                }else if (dataType == 3){
                    
                    if(isDouble(retval)){
                        
						array.add((T)new Double(retval));
                    }

                    else{
                        
                        throw new myException("Bad data for int");
                    }
                }
   
                countForNumGrams++;

            }

            peyir = new Pair[countForNumGrams-1];

            for(int z = 0 ; z < countForNumGrams-1 ; z++){

                peyir[z] = new Pair(array.get(z),array.get(z+1));

            }//pair oluşturuyor


            for (int i = 0 ; i < peyir.length; i++){

				if(mymap.containsKey(peyir[i]))
				
					mymap.put(peyir[i], mymap.get(peyir[i])+1);
					 
				else
					mymap.put(peyir[i], 1);

            }//end for

                    
            }//end try

        catch(FileNotFoundException fileNotFoundException){
            
            System.err.println("File could not found");        
        }
        catch(IOException ioException){
            
            System.err.println("File could not found");        
        }
        
        
        
    }//end of function
    
    @Override
    public int numGrams(){
        
        return countForNumGrams-1;
    }
    
    @Override
    public int numOfGrams(T var1,T var2){

		Integer result;
		
        result = mymap.get(new Pair(var1, var2));
        
        if(result == null)
        
			return 0;
			
		else
		
			return result.intValue();
    }
    
    @Override
    public String toString(){
        
        StringBuilder result = new StringBuilder();
        
        int maxValue=(Collections.max(mymap.values()));

        for(int max=maxValue ; max > 0 ; max--){

            for (Entry<Pair<T,T>,Integer> entry : mymap.entrySet()) {

                if (entry.getValue()==max) {

                    result.append("map.first : "+entry.getKey() + " num: " + entry.getValue() + "\n");    
                }
            }
        }
        return result.toString();
    }
    
}//end of class
