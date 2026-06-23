----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10.06.2024 10:45:16
-- Design Name: 
-- Module Name: test - Behavioral
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

entity test is
--  Port ( );
end test;

architecture Behavioral of test is
component top is
    Port ( JB : out STD_LOGIC_VECTOR(5 DOWNTO 0);
           led: out std_logic_vector(7 downto 0);
           tx : out STD_LOGIC;
           rx : in STD_LOGIC;
           bot: in std_logic_vector(4 downto 0);
           clk: in std_logic;
           rst: in std_logic);
end component;

signal tx,rx,clk,rst: std_logic;
signal bot:std_logic_vector(4 downto 0);
signal JB:std_logic_vector(5 downto 0);
signal led:std_logic_vector(7 downto 0);
begin
dut: TOP port map (rst=>rst, tx=>tx, rx=>rx, clk=>clk, bot=>bot, JB=>JB, led=>led);

erlojua: process
begin
    clk<='0';
    wait for 10 ns;
    clk<='1';
    wait for 10 ns;
end process;

test: process
begin
    rst<='1';
    rx<='0';
    bot<="00000";
    JB<="ZZZZZZ";
    
wait for 15 ns;
     rst<='0';
    rx<='1';
    bot<="10000";
    JB<="ZZZZZZ";

wait for 15 ns;
     rst<='0';
    rx<='1';
    bot<="01000";
    JB<="ZZZZZZ";
wait for 15 ns;
    rst<='0';
    rx<='1';
    bot<="00100";
    JB<="ZZZZZZ";
wait for 15 ns;
    rst<='0';
    rx<='1';
    bot<="00000";
    JB<="000000";
wait for 15 ns;
    rst<='0';
    rx<='1';
    bot<="00010";
    JB<="ZZZZZZ";
wait for 15 ns;
    rst<='0';
    rx<='1';
    bot<="00001";
    JB<="ZZZZZZ";
end process;

end Behavioral;
