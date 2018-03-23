public class DynamicArray<T> {
    
    private T a ;
    
    private T b ;
    
    private int value = 0;
    
    public DynamicArray(){

        this.a = null;

        this.b = null;
        
    }
    
    public void seta(T var1){
        
        a = var1;
    }
    public void setb(T var1){
        
        b = var1;
    }
    public void setvalue(int var1){
        
        value = var1;
    }
    
    public T geta(){
        return a ;
    }
    
    public T getb(){
        return b;
    }
    public int getvalue(){
        
        return value;
    }
 
}
