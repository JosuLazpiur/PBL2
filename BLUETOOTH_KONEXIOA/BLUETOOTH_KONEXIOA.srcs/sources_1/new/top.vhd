----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.05.2024 17:52:55
-- Design Name: 
-- Module Name: top - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity top is
    Port ( JB : out STD_LOGIC_VECTOR(5 DOWNTO 0);
           led: out std_logic_vector(7 downto 0);
           tx : out STD_LOGIC;
           rx : in STD_LOGIC;
           bot: in std_logic_vector(4 downto 0);
           clk: in std_logic;
           rst: in std_logic);
end top;

architecture Behavioral of top is
component Fzati is
    Port ( rst : in STD_LOGIC;
           clk : in STD_LOGIC;
           en_16_x_baud : out STD_LOGIC);
end component;
component kcuart_rx is
    Port (            serial_in : in std_logic;  
                 data_out : out std_logic_vector(7 downto 0);
              data_strobe : out std_logic;
             en_16_x_baud : in std_logic;
                      clk : in std_logic);
end component;
component EM_RX is
    Port ( clk : in STD_LOGIC;
            jasotzen: out std_logic_vector (7 downto 0);
           data_out : in STD_LOGIC_VECTOR (7 downto 0);
           data_strobe : in STD_LOGIC;
           rst : in STD_LOGIC);
end component;
component Fzati2 is
    Port ( rst : in STD_LOGIC;
           clk : in STD_LOGIC;
           en_16_x_baud : out STD_LOGIC);
end component;
component kcuart_tx is
    Port (        data_in : in std_logic_vector(7 downto 0);
           send_character : in std_logic;
             en_16_x_baud : in std_logic;
               serial_out : out std_logic;
              Tx_complete : out std_logic;
                      clk : in std_logic);
end component;
component EM_TX is
    Port ( clk : in STD_LOGIC;
           rst : in STD_LOGIC;
           bot: in std_logic_vector(4 downto 0);
           data: out std_logic_vector(7 downto 0);
           tx_complete : in STD_LOGIC;
           send_char : out STD_LOGIC);
end component;

signal s_enable, s_enable2, data_strobe: std_logic;
signal data_out, data_in: std_logic_vector(7 downto 0);
signal tx_complete, send_char: std_logic;

begin

U1: Fzati port map(clk=>clk,rst=>rst,en_16_x_baud=>s_enable);
U2: kcuart_rx port map(clk=>clk, data_out=>data_out, serial_in=>rx, en_16_x_baud=>s_enable,
                       data_strobe=>data_strobe);
U3: EM_RX port map(clk=>clk, rst=>rst, data_strobe=>data_strobe, data_out=>data_out, jasotzen=>led);
U4: Fzati2 port map(clk=>clk, rst=>rst, en_16_x_baud=>s_enable2);
U5: kcuart_tx port map(clk=>clk, send_character=>send_char, serial_out=>tx, Tx_complete=>
                        tx_complete, en_16_x_baud=>s_enable2, data_in=>data_in);
U6: EM_TX port map(clk=>clk, rst=>rst,bot=>bot, data=>data_in, send_char=>send_char, tx_complete=>
                tx_complete);

JB(0)<='Z';
JB(1)<='Z';
JB(2)<='Z';
JB(3)<='Z';
JB(4)<='Z';
JB(5)<='Z';

end Behavioral;
