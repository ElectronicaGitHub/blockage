//компонент, отвечающий за изменение движения. Типа - стоял, пошел. Двигался влево, стал двигаться вправо. Под одним углом, под другим. И т.д.
//
//типа:
//class Engine < Component
//    attr_accessor :speed, :forward, :rotation, :control_move, :on
//
//    def initialize(speed, on = false, rotation = 0, control_move = false)
//        super()
//        @rotation = rotation
//        @speed = speed
//        @on = on
//        @rotation = rotation
//        @control_move = control_move
//        @forward = true
//    end
//
//    def rotate(amount)
//        @rotation += amount
//    end
//
//    def move(forward = true)
//        @on = true
//        @forward = forward
//    end
//
//    def stop
//        @on = false
//    end
//end