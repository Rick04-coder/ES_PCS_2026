% Legge i dati ignorando l'intestazione
data = readmatrix('tempi_ordinamento.txt', 'NumHeaderLines', 1);

N = data(:,1);
t_bubble = data(:,2);
t_select = data(:,3);
t_insert = data(:,4);
t_merge  = data(:,5);
t_quick  = data(:,6);
t_qmod   = data(:,7);
t_std    = data(:,8);

figure;
% Uso loglog perché i tempi variano di molti ordini di grandezza.
% Supporto AI per abbellimento grafici
loglog(N, t_bubble, '-o', 'DisplayName', 'Bubble Sort'); hold on;
loglog(N, t_select, '-x', 'DisplayName', 'Selection Sort');
loglog(N, t_insert, '-d', 'DisplayName', 'Insertion Sort');
loglog(N, t_merge,  '-s', 'DisplayName', 'Merge Sort');
loglog(N, t_quick,  '-v', 'DisplayName', 'Quick Sort');
loglog(N, t_qmod,   '-*', 'LineWidth', 2, 'DisplayName', 'Quick Mod (Hybrid)');
loglog(N, t_std,    '--k', 'LineWidth', 2, 'DisplayName', 'std::sort');

grid on;
xlabel('Dimensione Vettore (N)');
ylabel('Tempo medio (secondi)');
title('Confronto Prestazioni Algoritmi di Ordinamento');
legend('Location', 'northwest');