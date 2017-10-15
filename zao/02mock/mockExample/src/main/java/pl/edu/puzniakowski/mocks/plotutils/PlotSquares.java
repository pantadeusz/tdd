package pl.edu.puzniakowski.mocks.plotutils;

import pl.edu.puzniakowski.mocks.plotters.PlotterDriver;

public class PlotSquares {

    private PlotterDriver plotterDriver;

    public void setPlotterDriver(PlotterDriver driver) {
        this.plotterDriver = driver;
        plotterDriver.resetPosition();
    }

    public void drawSquareInPlace(int r) throws IllegalArgumentException {
        int x0 = plotterDriver.getPositionX();
        int y0 = plotterDriver.getPositionY();
        plotterDriver.gotoXY(x0 - r, y0 - r);
        plotterDriver.gotoXY(x0 + r, y0 - r);
        plotterDriver.gotoXY(x0 + r, y0 + r);
        plotterDriver.gotoXY(x0 - r, y0 + r);
    }

}
