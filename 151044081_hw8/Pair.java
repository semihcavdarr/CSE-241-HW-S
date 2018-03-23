public class Pair<T1,T2> {
    
    private T1 first;
    
    private T2 second;
    
    public Pair(){
        
        first = null;
        
        second = null;
    }
    public Pair(T1 var1,T2 var2){

        first = var1;

        second = var2;

    }
    
    public T1 getfirst(){
        
        return first;
    }
    public T2 getsecond(){
        
        return second;
    }
    public void setfirst(T1 var){
        
        first = var;
    }
    public void setsecond(T2 var){
        
        second = var;
    }
    
    @Override
    public boolean equals(Object o){
    
		if((o instanceof Pair) == false)
			
			return false;
	
		Pair p = (Pair)o;
		
		if(this.getfirst().equals(p.getfirst()) &&
			this.getsecond().equals(p.getsecond()))
			
				return true;
				
		return false;
	}
   
    @Override
    public int hashCode(){
    
		return this.toString().hashCode();
    }
    
    public String toString(){
    
		StringBuilder stringBuilder = new StringBuilder();
		
		stringBuilder.append(this.getfirst());
		stringBuilder.append(" - ");
		stringBuilder.append(this.getsecond());
    
		return stringBuilder.toString();
		
    }
}
