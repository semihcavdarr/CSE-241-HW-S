public interface Bigram<T>{
    
    public void readFile(String filename) throws Exception;
    
    public int numGrams();
    
    public int numOfGrams(T var1,T var2);
    
    @Override
    public String toString();
    
}
