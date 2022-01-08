package carfactory;

public class Car {
	private int carNumber;

	public Car() {
		CarFactory.carNum++;
		carNumber = CarFactory.carNum;
	}

	public int getCarNum() {
		return carNumber;
	}
}
