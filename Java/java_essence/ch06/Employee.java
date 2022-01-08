import java.util.Date;

class Employee{
	public Employee(String name, String address, String telno, Date joindate){
		m_name = name;
		m_address = address;
		m_telno = telno;
		m_joindate = joindate;
	}

	public void displayEmployee(){ // 사원 정보 표시
		System.out.printf("name : %s\naddress : %s\ntelno : %s\njoindate : %s\n", m_name, m_address, m_telno, m_joindate);
	}

	private String m_name; // 사원명
	private String m_address; // 주소
	private String m_telno; // 전화번호
	private Date m_joindate; // 입사일
}
