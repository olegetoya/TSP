    fid = fopen('tsp_data.txt', 'rt');
    n = fscanf(fid, '%d', 1);
    coords = fscanf(fid, '%f', [2, n])';
    fclose(fid);

    fid = fopen('route.txt', 'rt');
    route = fscanf(fid, '%d')';
    fclose(fid);

    plot(coords(:,1), coords(:,2), 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 8);
    hold on;
    grid on;

    for i = 1:length(route)-1
        plot(coords(route(i:i+1), 1), coords(route(i:i+1), 2), 'b-', 'LineWidth', 2);
    end
    plot([coords(route(end), 1), coords(route(1), 1)], [coords(route(end), 2), coords(route(1), 2)], 'b-', 'LineWidth', 2);

    hold off;
    title('Визуализация пути решения задачи коммивояжера');
    xlabel('X координата');
    ylabel('Y координата');
    print('Gpaph.png', '-dpng');

