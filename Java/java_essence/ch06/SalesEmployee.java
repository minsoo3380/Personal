import java.util.Date;

class SalesEmployee extends RegularEmployee {
	public SalesEmployee(String name, String address, String telno, Date joindate, double salary, double commission){
		// 생략
	}

	/*
	public double payCheck() { // 급여 ㄱㅖ산
		return m_salary + (m_sales * m_commission);
	}
	*/

	public double payCheck() {
		return super.payCheck() + (m_sales * m_commission);
	}

	private double m_sales; // 영업실적
	private double m_commission; // 영업수당
}
