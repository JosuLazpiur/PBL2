----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.05.2024 18:10:21
-- Design Name: 
-- Module Name: EM_RX - Behavioral
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

entity EM_RX is
    Port ( clk : in STD_LOGIC;
            jasotzen: out std_logic_vector (7 downto 0);
           data_out : in STD_LOGIC_VECTOR (7 downto 0);
           data_strobe : in STD_LOGIC;
           rst : in STD_LOGIC);
end EM_RX;

architecture Behavioral of EM_RX is
type egoera is (hasiera, jaso);
signal oraingoa, hurrengoa: egoera;
begin

sek: process (clk, rst)
begin
if rst='1' then 
    oraingoa<= hasiera;
elsif clk'event and clk ='1' then
    oraingoa<=hurrengoa;
      if oraingoa=jaso then
        jasotzen<=data_out;
      end if;
    end if;
end process;
konb: process (oraingoa)
begin
    case oraingoa is
        when hasiera =>
            if data_strobe = '1' then
                hurrengoa<=jaso;
            end if;
        when jaso =>
            if data_strobe = '0' then
                hurrengoa<=hasiera;
            end if;
    end case;
end process;


end Behavioral;