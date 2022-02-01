package practice;

public class EvenArray {
	public static void main(String[] args) {
		int[] even = new int[5];

		for(int i = 1; i < 11; i++) {
			if((i % 2) == 0) {
				even[(i / 2) - 1] = i;
			}
		}

		for(int i : even) {
			System.out.println(i);
		}
	}
}
