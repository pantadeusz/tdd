package bddexample;

import java.util.LinkedList;
import java.util.List;

public class Calculator {
    LinkedList<Double> args = new LinkedList<>();
    public void addArg(Double arg1) {
        args.push(arg1);
    }

    public void sum() {
        args.push(args.pop() + args.pop());
    }

    public Double getResult() {
        return args.pop();
    }

    public void addArgs(List<Double> arg1) {
        for (Double d: arg1) args.push(d);
    }
}
