data = load('dati_sorting.txt');

N = data(:, 1);
t_bubble = data(:, 2);
t_insert = data(:, 3);
t_select = data(:, 4);
t_std    = data(:, 5);

figure;
plot(N, t_bubble, '-o', 'LineWidth', 2); hold on;
plot(N, t_insert, '-s', 'LineWidth', 2);
plot(N, t_select, '-d', 'LineWidth', 2);
plot(N, t_std,    '-x', 'LineWidth', 2);

grid on;
xlabel('Dimensione del vettore (N)');
ylabel('Tempo di esecuzione (secondi)');
title('Confronto Performance Algoritmi di Ordinamento');
legend('Bubble Sort', 'Insertion Sort', 'Selection Sort', 'std::sort', 'Location', 'northwest');

saveas(gcf, 'confronto_sorting.png'); % Salva il grafico come immagine