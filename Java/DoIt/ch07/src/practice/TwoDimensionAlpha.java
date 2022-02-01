package practice;

public class TwoDimensionAlpha {
	public static void main(String[] args) {
		char[][] alpha = new char[13][2];
		char ch = 'a';

		for(int i = 0; i < alpha.length; i++) {
			for(int j = 0; j < alpha[i].length; j++) {
				alpha[i][j] = ch++;
			}
		}

		for(int i = 0; i < alpha.length; i++) {
			for(int j = 0; j < alpha[i].length; j++) {
				System.out.print((char)(alpha[i][j] - 32));
			}
			System.out.println();
		}
	}
}
