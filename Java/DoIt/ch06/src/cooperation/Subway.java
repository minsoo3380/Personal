package cooperation;

public class Subway {
	String lineNumber;		// 지하철 노선
	int passengerCount;		// 승객 수
	int money;				// 수입액

	public Subway(String lineNumber) {
		this.lineNumber = lineNumber;
	}

	public void take(int money) {
		this.money += money;	// 수입 증가
		passengerCount++;
	}

	public void showInfo() {
		System.out.println(lineNumber + "의 승객은 " + passengerCount + "명이고, 수입은 " + money + "입니다.");
	}
}

