import java.util.Date;

// RegularEmployee.java 파일
// 일반 사원 클래스
class RegularEmployee extends Employee{
	public RegularEmployee(String name, String address, String telno, Date joindate, double salary){
		super(name, address, telno, joindate); // 수퍼 클래스 생성자 호출
		m_salary = salary;
	}

	public double payCheck(){ // 급역 ㄱㅖ산
		return m_salary *= 0.15;
	}
	
	//private double m_salary; // 급여
	protected double m_salary; // 급여
}

