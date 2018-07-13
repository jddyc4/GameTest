using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace TicTacToe
{

    public enum Symbol
    {
        empty,
        cross,
        circle
    }
    
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        #region Private Members
        private Symbol[] board;
        private bool player1Turn;
        private bool winner;
        #endregion

        #region Constructor
        public MainWindow()
        {
            InitializeComponent();

            NewGame();
        }
        #endregion

        private void NewGame()
        {
            board = new Symbol[9];

            for (var i = 0; i < board.Length; i++)
            {
                board[i] = Symbol.empty;
            }

            player1Turn = true;
            winner = false;

            //Iterate every button on grid
            //looked at container, got the children, converted them to buttons, made them
            //into a solid list so we could call forEach to go over every button
            Container.Children.Cast<Button>().ToList().ForEach(button => {
                button.Content = null;
                button.Background = Brushes.White;
                button.Foreground = Brushes.Blue;
            });
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            int column;
            int row;
            int index;
            var button = (Button)sender;

            if (winner)
            {
                NewGame();
                return;
            }

            column = Grid.GetColumn(button);
            row = Grid.GetRow(button);

            index = column + (row * 3);

            if (board[index] != Symbol.empty)
            {
                return;
            }

            board[index] = player1Turn ? Symbol.cross : Symbol.circle;
            button.Content = player1Turn ? "X" : "O";

            if (!player1Turn)
            {
                button.Foreground = Brushes.Red;
            }

            player1Turn = !player1Turn;

            checkForWinner();

            //computerTurn();
        }

        private void checkForWinner()
        {
            //Check for horizontal wins: Row 0
            if (board[0] != Symbol.empty && (board[0] & board[1] & board[2]) == board[0])
            {
                winner = true;
                Button00.Background = Button10.Background = Button20.Background = Brushes.Green;
            }

            //Row 1
            if (board[3] != Symbol.empty && (board[3] & board[4] & board[5]) == board[3])
            {
                winner = true;
                Button01.Background = Button11.Background = Button21.Background = Brushes.Green;
            }
          
            //Row 2
            if (board[6] != Symbol.empty && (board[6] & board[7] & board[8]) == board[6])
            {
                winner = true;
                Button02.Background = Button12.Background = Button22.Background = Brushes.Green;
            }

            // Column 0
            if (board[0] != Symbol.empty && (board[0] & board[3] & board[6]) == board[0])
            {
                winner = true;
                Button00.Background = Button01.Background = Button02.Background = Brushes.Green;
            }
       
            //column 1
            if (board[1] != Symbol.empty && (board[1] & board[4] & board[7]) == board[1])
            {
                winner = true;
                Button10.Background = Button11.Background = Button12.Background = Brushes.Green;
            }
         
            //Column 2
            if (board[2] != Symbol.empty && (board[2] & board[5] & board[8]) == board[2])
            {
                winner = true;
                Button20.Background = Button21.Background = Button22.Background = Brushes.Green;
            }

            // Diagonal (\)
            if (board[0] != Symbol.empty && (board[0] & board[4] & board[8]) == board[0])
            {
                winner = true;
                Button00.Background = Button11.Background = Button22.Background = Brushes.Green;
            }
            // Diagonal (/)
            if (board[2] != Symbol.empty && (board[2] & board[4] & board[6]) == board[2])
            {
                winner = true;
                Button20.Background = Button11.Background = Button02.Background = Brushes.Green;
            }

            if (winner)
            {
                return;
            }

            if (!board.Any(f => f == Symbol.empty))
            {
                winner = true;
                Container.Children.Cast<Button>().ToList().ForEach(button =>
                {
                    button.Background = Brushes.Orange;
                });
            }
        }

        private void computerTurn()
        {
            
        }
    }
}
