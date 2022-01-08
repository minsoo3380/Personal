import java.util.Date;

class mEmployee{
	public static void main(String[] args){
		Date joindate = new Date(2012, 1, 1);
		RegularEmployee re = new RegularEmployee("전병선", "서울시", "123-4567", joindate, 1000000000);
		re.displayEmployee(); // 수퍼 클래스 메서드 호출
		double salary = re.payCheck(); // 서브 클래스 메서드 호출
		System.out.printf("급여액 : %f 원\n", salary);
	}
}
