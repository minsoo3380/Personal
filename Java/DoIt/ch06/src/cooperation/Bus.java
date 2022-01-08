package cooperation;

public class Bus {
	int busNumber;			// 버스 번호
	int passengerCount;		// 승객 수 
	int money;				// 버스 수임

	public Bus(int busNumber) {
		this.busNumber = busNumber;
	}

	public void take(int money) {
		this.money += money;	// 버스 수입 증가
		passengerCount++;		// 승객 수 증가
	}

	public void showInfo() {
		System.out.println("버스 " + busNumber + "번의 승객은 " + passengerCount + "명이고, 수입은 " + money + "입니다.");
	}
}
