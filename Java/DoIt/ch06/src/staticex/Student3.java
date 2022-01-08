package staticex;

public class Student3 {
	private static int serialNum = 1000;
	int studentID;
	String studentName;
	int grade;
	String address;
	int studentCard;

	public Student3() {
		serialNum++;
		studentID = serialNum;
		studentCard = Student3.serialNum + 100;
	}

	public String getStudentName() {
		return studentName;
	}

	public void setStudentName(String name) {
		this.studentName = name;
	}

	public int getStudentCard() {
		return studentCard;
	}

	public static int getSerialNum() {
		int i = 10;
		return serialNum;
	}

	public static void setSerialNum(int serialNum) {
		Student3.serialNum = serialNum;
	}
}

