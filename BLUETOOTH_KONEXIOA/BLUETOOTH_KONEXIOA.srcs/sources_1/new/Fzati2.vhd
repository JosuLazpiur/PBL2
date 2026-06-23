----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.05.2024 17:57:32
-- Design Name: 
-- Module Name: Fzati2 - Behavioral
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Fzati2 is
    Port ( rst : in STD_LOGIC;
           clk : in STD_LOGIC;
           en_16_x_baud : out STD_LOGIC);
end Fzati2;

architecture Behavioral of Fzati2 is

signal kont:std_logic_vector(54 downto 0);

begin
baud_timer: process(clk)
begin
    if rst='1' then
        en_16_x_baud<='0';
    elsif clk'event and clk = '1' then
        if kont=54 then
            kont<= (others=>'0');
            en_16_x_baud<='1';
        else
            kont<=kont+1;
            en_16_x_baud<='0';
        end if;
    end if;
end process;

end Behavioral;