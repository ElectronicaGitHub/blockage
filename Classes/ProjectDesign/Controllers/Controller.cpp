//в контроллере должна быть какая-то вот такая логика:
//class Controller
//    attr_reader :game
//
//    def initialize(state)
//        @state = state # не уверен, что нужно, но что-то мне подсказывает
//    end
//
//    # самое главное:
//    def process_one_game_tick
//        raise RuntimeError, "systems must override process_one_game_tick()"
//    end
//end