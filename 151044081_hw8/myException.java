public class myException extends Exception{

	private String hata ;

	myException(String _hata){

		hata = _hata;
	}

	public String toString(){

		return hata;
	}
}