----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.05.2024 18:33:59
-- Design Name: 
-- Module Name: EM_TX - Behavioral
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

entity EM_TX is
    Port ( clk : in STD_LOGIC;
           rst : in STD_LOGIC;
           bot: in std_logic_vector(4 downto 0);
           data: out std_logic_vector(7 downto 0);
           tx_complete : in STD_LOGIC;
           send_char : out STD_LOGIC);
end EM_TX;

architecture Behavioral of EM_TX is

type egoera is (itxoiten, bidaltzen);
signal oraingoa, hurrengoa: egoera;
begin

sek: process (clk, rst)
begin
if rst='1' then 
    oraingoa<= itxoiten;
elsif clk'event and clk ='1' then
    oraingoa<=hurrengoa;
    end if;
end process;
konb: process (oraingoa)
begin
    case oraingoa is
        when itxoiten =>
            send_char<='0';
            if bot(0) = '1' then
                data<="01110111";-- w letra                      
                hurrengoa<=bidaltzen;
            elsif bot(1) = '1' then
                data<="01100001"; --a letra                      
                hurrengoa<=bidaltzen;
            elsif bot(2) = '1' then
                data<="01100100";  --d letra              
                hurrengoa<=bidaltzen;
            elsif bot(3) = '1' then
                data<="01110011"; -- s letra                      
                hurrengoa<=bidaltzen;
            elsif bot(4) = '1' then
                data<="01100110"; --f letra                    
                hurrengoa<=bidaltzen;                
            else
            data<="00000000";-- ezer
            end if;
        when bidaltzen =>
            send_char<='1';
            if tx_complete = '1' then
                hurrengoa<=itxoiten;
            end if;                                                 
    end case;
end process;

end Behavioral;
