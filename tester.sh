echo "Installing...";
make;
echo "$(tput setaf 2)File name : a$(tput setaf 7)";./so_long maps/a;
echo "$(tput setaf 2)File name : gber$(tput setaf 7)";./so_long maps/gber;
echo "$(tput setaf 2)File name : ber$(tput setaf 7)"; ./so_long maps/ber;
echo "$(tput setaf 2)Wrong walls$(tput setaf 7)"; ./so_long maps/map_wrongleft.ber;
echo "$(tput setaf 2)Wrong walls$(tput setaf 7)";./so_long maps/map_wrongup.ber;
echo "$(tput setaf 2)Sans argument$(tput setaf 7)";./so_long;
echo "$(tput setaf 2)Map sans joueur$(tput setaf 7)";./so_long maps/map_no_p.ber;
echo "$(tput setaf 2)Map sans exit$(tput setaf 7)";./so_long maps/map_no_e.ber;
echo "$(tput setaf 2)Map sans collectibles$(tput setaf 7)";./so_long maps/map_no_c.ber;
echo "$(tput setaf 2)Map avec plusieurs joueurs$(tput setaf 7)";./so_long maps/map_two_player.ber;
echo "$(tput setaf 2)Lancement d'une vraie map$(tput setaf 7)";./so_long maps/map_valid.ber;
