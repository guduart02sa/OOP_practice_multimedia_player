import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

public class main_window extends JFrame {

  static Client client = null;

  private static final long serialVersionUID = 1L;
  static String DEFAULT_HOST = "localhost";
  static int DEFAULT_PORT = 3331;
  static String host = DEFAULT_HOST;
  static int port = DEFAULT_PORT;
  private Socket sock;
  private BufferedReader input;
  private BufferedWriter output;

  static JTextArea text_zone;
  private JTextField requestField;

  public main_window() {
    super("Fenetre Principale");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    // Création de la zone de texte
    text_zone = new JTextArea(10, 20);
    text_zone.setEditable(false);
    JScrollPane scrollPane = new JScrollPane(text_zone);
    add(scrollPane, BorderLayout.CENTER);

    // Création du champ de requête
    requestField = new JTextField(20);
    requestField.setForeground(Color.GRAY);
    requestField.setText(
      "Write your request and click send request or the name of group/media and one of the buttons to modify/show the group/media"
    );
    requestField.addFocusListener(
      new FocusListener() {
        @Override
        public void focusGained(FocusEvent e) {
          if (
            requestField
              .getText()
              .equals(
                "Write your request and click send request or the name of group/media and one of the buttons to modify/show the group/media"
              )
          ) {
            requestField.setText("");
            requestField.setForeground(Color.BLACK);
          }
        }

        @Override
        public void focusLost(FocusEvent e) {
          if (requestField.getText().isEmpty()) {
            requestField.setForeground(Color.GRAY);
            requestField.setText(
              "Write your request and click send request or the name of group/media and one of the buttons to modify/show the group/media"
            );
          }
        }
      }
    );
    add(requestField, BorderLayout.SOUTH);

    // Création de la barre de menus
    JMenuBar menuBar = new JMenuBar();
    JMenu menu = new JMenu("Menu");
    JMenuItem menuItem1 = new JMenuItem("Send request");
    JMenuItem menuItem2 = new JMenuItem("Play Media");
    JMenuItem menuItemExit = new JMenuItem("Exit");
    JMenuItem menuItemDisplayMedia = new JMenuItem("Display Media");
    JMenuItem menuItemDisplayGroup = new JMenuItem("Display Group");
    JMenuItem menuItemDelete = new JMenuItem("Delete");

    menu.add(menuItem1);
    menu.add(menuItem2);
    menu.add(menuItemDisplayMedia);
    menu.add(menuItemDisplayGroup);
    menu.add(menuItemDelete);
    menu.addSeparator();
    menu.add(menuItemExit);
    menuBar.add(menu);
    setJMenuBar(menuBar);

    // Création de la barre d'outils
    JToolBar toolBar = new JToolBar();
    JButton button1 = new JButton("Send request");
    JButton button2 = new JButton("Play Media");
    JButton buttonExit = new JButton("Exit");
    JButton buttonDisplayMedia = new JButton("Display Media");
    JButton buttonDisplayGroup = new JButton("Display Group");
    JButton buttonDelete = new JButton("Delete");

    toolBar.add(button1);
    toolBar.add(button2);
    toolBar.add(buttonDisplayMedia);
    toolBar.add(buttonDisplayGroup);
    toolBar.add(buttonDelete);
    toolBar.addSeparator();
    toolBar.add(buttonExit);
    add(toolBar, BorderLayout.NORTH);

    // Définition des actions des buttons
    Action action1 = new AbstractAction("Send request") {
      public void actionPerformed(ActionEvent e) {
        String request = requestField.getText();
        String answer = client.send(request);
        text_zone.append(answer + "\n");
      }
    };

    Action action2 = new AbstractAction("Play Media") {
      public void actionPerformed(ActionEvent e) {
        String request = "play media " + requestField.getText();
        text_zone.append("play media " + requestField.getText() + "\n");
        String answer = client.send(request);
        text_zone.append(answer + "\n");
      }
    };

    Action actionExit = new AbstractAction("Exit") {
      public void actionPerformed(ActionEvent e) {
        System.exit(0);
      }
    };

    Action actionDisplayMedia = new AbstractAction("Display media") {
      public void actionPerformed(ActionEvent e) {
        String request = "display media " + requestField.getText();
        String answer = client.send(request);
        text_zone.append(answer);
      }
    };

    Action actionDisplayGroup = new AbstractAction("Display group") {
      public void actionPerformed(ActionEvent e) {
        String request = "display group" + requestField.getText();
        String answer = client.send(request);
        text_zone.append(answer);
      }
    };

    Action actionDelete = new AbstractAction("Delete") {
      public void actionPerformed(ActionEvent e) {
        text_zone.append(requestField.getText() + " deleted\n");
      }
    };

    menuItem1.addActionListener(action1);
    menuItem2.addActionListener(action2);
    menuItemExit.addActionListener(actionExit);
    menuItemDisplayMedia.addActionListener(actionDisplayMedia);
    menuItemDisplayGroup.addActionListener(actionDisplayGroup);

    menuItemDelete.addActionListener(actionDelete);

    button1.setAction(action1);
    button2.setAction(action2);
    buttonExit.setAction(actionExit);
    buttonDisplayMedia.setAction(actionDisplayMedia);
    buttonDisplayGroup.setAction(actionDisplayGroup);
    buttonDelete.setAction(actionDelete);

    pack();
    setVisible(true);
  }

  // SERVER INTERFACE//
  //======================================//
  private static class Client {

    private Socket sock;
    private BufferedReader input;
    private BufferedWriter output;

    public Client(String host, int port)
      throws UnknownHostException, IOException {
      try {
        sock = new java.net.Socket(host, port);
      } catch (java.net.UnknownHostException e) {
        System.err.println("Client: Couldn't find host " + host + ":" + port);
        text_zone.append(
          "Client: Couldn't find host " + host + ":" + port + "\n"
        );
        throw e;
      } catch (java.io.IOException e) {
        System.err.println("Client: Couldn't reach host " + host + ":" + port);
        text_zone.append(
          "Client: Couldn't reach host " + host + ":" + port + "\n"
        );
        throw e;
      }

      try {
        input =
          new BufferedReader(new InputStreamReader(sock.getInputStream()));
        output =
          new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
      } catch (java.io.IOException e) {
        System.err.println("Client: Couldn't open input or output streams");
        throw e;
      }
    }

    public String send(String request) {
      // Envoyer la requete au serveur
      try {
        request += "\n"; // ajouter le separateur de lignes
        output.write(request, 0, request.length());
        output.flush();
      } catch (java.io.IOException e) {
        System.err.println("Client: Couldn't send message: " + e);
        text_zone.append("Client: Couldn't send message: " + e + "\n");
        return null;
      }

      // Recuperer le resultat envoye par le serveur
      try {
        return input.readLine();
      } catch (java.io.IOException e) {
        System.err.println("Client: Couldn't receive message: " + e);
        text_zone.append("Client: Couldn't receive message: " + e + "\n");
        return null;
      }
    }
  }

  public static void main(String[] argv) {
    if (argv.length >= 1) host = argv[0];
    if (argv.length >= 2) port = Integer.parseInt(argv[1]);

    try {
      client = new Client(host, port);
    } catch (Exception e) {
      System.err.println("Client: Couldn't connect to " + host + ":" + port);
      text_zone.append(
        "Client: Couldn't connect to " + host + ":" + port + "\n"
      );
      System.exit(1);
    }


    System.out.println("Client connected to " + host + ":" + port);
    new main_window();
    text_zone.append("Client connected to " + host + ":" + port + "\n");

  }
}
