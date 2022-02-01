package practice;

public class Dog {
	private String name;
	private String type;

	public void setName(String name) {
		this.name = name;
	}

	public String getName() {
		return name;
	}

	public void setType(String type) {
		this.type = type;
	}

	public String getType() {
		return type;
	}

	public String showDogInfo() {
		return name + "," + type;
	}
}
