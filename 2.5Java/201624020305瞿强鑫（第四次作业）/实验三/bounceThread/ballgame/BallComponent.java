import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.geom.Rectangle2D;
import java.util.*;
import javax.swing.*;

package ballgame; 

/**
 * The component that draws the balls.
 * @version 1.34 2012-01-26
 * @author Cay Horstmann
 */
public class BallComponent extends JComponent
{
   private static final int DEFAULT_WIDTH = 800;
   private static final int DEFAULT_HEIGHT = 600;

   private java.util.List<Ball> balls = new ArrayList<>();

   /**
    * Add a ball to the panel.
    * @param b the ball to add
    */
   public void add(Ball b)
   {
      balls.add(b);
   }

   public void paintComponent(Graphics g)
   {
      Graphics2D g2 = (Graphics2D) g;
      Paint paint = g2.getPaint();
      g2.setPaint(Color.RED);
      g2.fillRect(x,y,w,h);
      g2.setPaint(paint);
      for (Ball b : balls)
      {
          if(b.getX() + Ball.getXSIZE() > x
                  && b.getX() < x + w
                  && b.getY() + Ball.getYSIZE() > y
                  && b.getY() < y + h)
              b.setDy(-b.getDy());
         g2.fill(b.getShape());
      }
   }
   
   public Dimension getPreferredSize() { return new Dimension(DEFAULT_WIDTH, DEFAULT_HEIGHT); }

   //to Add code here
    private int x = 400,y = 550,w = 100,h = 10;
    {
        addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                super.mouseMoved(e);
                x = e.getX() + h/2;
            }
        });
    }
}
