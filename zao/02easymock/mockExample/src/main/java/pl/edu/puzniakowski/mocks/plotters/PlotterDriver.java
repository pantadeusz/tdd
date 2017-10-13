package pl.edu.puzniakowski.mocks.plotters;
/*
   Java does not provide tuple or pairs. In this example I
   didn't want to create additional class for Vector or Coordinate
 */

public interface PlotterDriver {
    public void gotoXY(int x, int y);
    public int getPositionX();
    public int getPositionY();
    public void resetPosition();
}
