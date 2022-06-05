import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class AppWindow{

    private static final JTextField inputN = new JTextField();
    private static final JButton runButton = new JButton("Sort");
    private static final JComponent[] components = {runButton, inputN};
    private static void createAndShowGUI() {

        JFrame frame = new JFrame();
        JPanel content = new JPanel();
        frame.setContentPane(content);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        int windowX = 200;
        int windowY = 200;
        frame.setSize(windowX, windowY);
        frame.setMinimumSize(new Dimension(150, 150));
        frame.setMaximumSize(new Dimension(250, 250));

        runButton.setSize(100, 30);
        runButton.addActionListener(runAL);

        inputN.setMaximumSize(new Dimension(100,35));

        Box container = new Box(BoxLayout.Y_AXIS);
        container.setAlignmentX(Component.CENTER_ALIGNMENT);

        for ( JComponent component : components ) {
            component.setAlignmentX(Component.CENTER_ALIGNMENT);
            container.add(component);
        }

        content.setLayout(new BoxLayout(content, BoxLayout.Y_AXIS));
        content.add(Box.createVerticalGlue());
        content.add(container);
        content.add(Box.createVerticalGlue());

        content.repaint();
        frame.setVisible(true);
    }
    private static String runC() throws IOException, InterruptedException {
        StringBuilder text = new StringBuilder();

        String userText = inputN.getText();

        String cmd1 = "";
        try {
            cmd1 = String.format("src/qs %s", userText);
        } catch (NumberFormatException e) {
            cmd1 = "src/qs 1 2 3 4";
        }

        System.out.println(cmd1);
        Runtime run = Runtime.getRuntime();

        Process pr = run.exec(cmd1);
        pr.waitFor();

        BufferedReader buf = new BufferedReader(new InputStreamReader(pr.getInputStream()));
        String line;
        boolean first = true;
        while ((line=buf.readLine())!=null) {
            if ( first ) {
                first = false;
                text.append(line);
            }
            else
                text.append(", ").append(line);
        }
        return text.toString();
    }

    private static final ActionListener runAL = e -> {
        try {
            inputN.setText(runC());
        } catch (Exception ignored) {}
    };

    public static void main(String[] argv){
        AppWindow.createAndShowGUI();
    }
}
