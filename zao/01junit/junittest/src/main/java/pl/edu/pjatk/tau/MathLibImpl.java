package pl.edu.pjatk.tau;

public class MathLibImpl implements MathLib {
    public int add(int i, int i1) {
        return i+i1;
    }

    public int div(int i, int i1) throws ArithmeticException {
        return i/i1;
    }
}
